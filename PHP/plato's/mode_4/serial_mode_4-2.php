<?php

if (isset($argv))
    for ($i=1;$i<count($argv);$i++)
    {
        $it = explode("=",$argv[$i]);
        $_GET[$it[0]] = $it[1];
    }

$n="\n";
$brn="<br />\n";

date_default_timezone_set("Asia/Taipei");

//設定變數

//mode=0 無變數
//mode=1 凋謝速率
//mode=2 員工貢獻度
//mode=3 競爭
//mode=4 參考 v(敵人)

if(isset($_GET['debug'])) $debug=$_GET['debug'];
else $debug=1;//顯示步驟

if(isset($_GET['from'])) $from=$_GET['from'];
else $from=0;

if(isset($_GET['to'])) $to=$_GET['to'];
else $to=100;

if(isset($_GET['choice_time'])) $choice_time=$_GET['choice_time'];
else $choice_time=1;

if(isset($_GET['limit'])) $limit=$_GET['limit'];
else $limit=100;

if(isset($_GET['gap'])) $gap=$_GET['gap'];
else $gap=0.1;

if(isset($_GET['loop_num'])) $loop_num=$_GET['loop_num'];
else $loop_num=50;

printf("date,percent,=>,best,fail,fine,win $n");

 for($k=$from;$k<=$to;$k=$k+$gap){

 $percent=$k;

 $best=0;
 $fail=0;
 $fine=0;
 $win=0;

 if($debug>1){
  echo "From: ", $from, $n;
  echo "To: ", $to, $n;
  echo "Limit: ", $limit, $n;
  echo "Percent: ", $percent, $n;
  echo "Border: ", $limit*$percent/100, $n;
 } 
  
 for($j=0;$j<$loop_num;$j++){
  //變數設定
  
  $max_num=0;
  
  $max_percent=$limit*$percent/100;
  $army_max_percent=$limit*(100-$percent)/100;
  
  $percent_num=0;
  $army_percent_num=0;
  
  $choice=0;
  $army_choice=0;
  
  $time=0;
  $army_time=0;
  
  $thisnum=range(1,$limit,1);//（小,大,差）
  shuffle($thisnum);//洗牌
  
   for($i=0;$i<$limit;$i++){
    
    if($i>=$max_percent and $i-1<$max_percent) $time=$choice_time;
    if($limit-$i>=$army_max_percent and $limit-$i-1<$army_max_percent) $army_time=$choice_time;
    
    $num=$thisnum[$i];//我方此家分數
    $army_num=$thisnum[$limit-$i-1];//敵方此家分數
    
    if($max_num<=$num) $max_num=$num;//找尋最大值
    if($max_num<=$army_num) $max_num=$army_num;
    
    if($percent_num<$num) $percent_num=$num;
    if($army_percent_num<$army_num) $army_percent_num=$army_num;
    
    if($time>0 and $num>=$percent_num and $num>=$army_percent_num) {
    $choice=$choice+$num;
    $time=$time-1;
    $thisnum[$i]=0;
    }//拿走
    
    if($army_time>0 and $army_num>=$army_percent_num and $army_num>=$percent_num) {
    $army_choice=$army_choice+$army_num;
    $army_time=$army_time-1;
    $thisnum[$limit-$i-1]=0;
    }//敵方拿走
    
    if($debug>0) echo $i+1, " ", $num, " ", $army_num, "  ", $percent_num, " ", $army_percent_num, "  ", $time, " ", $army_time, $n;//顯示資訊
    
   }
  
  if($debug>0){
   echo "Choice: ", $choice, ",", $army_choice, $n;
   echo "Max: ", $max_num, $n;
  }
  
  if($max_num==$choice) $best++;
  if($choice==0) $fail++;
  if($max_num>$choice and $choice>0) $fine++;
  if($choice>$army_choice) $win++;
  
 }  

 $thedate=date("m-d H:i");
 printf("%s,%.1f,=>,%.7f,%.7f,%.7f,%.7f,(%.0f/%.0f)\n", $thedate, $percent, $best/$loop_num, $fail/$loop_num, $fine/$loop_num, $win/$loop_num, log($loop_num, 10), log($limit, 10));

} 

?>
