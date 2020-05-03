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
//mode=1 凋謝速率 v
//mode=2 員工貢獻度
//mode=3 競爭
//mode=4 參考

if(isset($_GET['debug'])) $debug=$_GET['debug'];
else $debug=1;//顯示步驟

if(isset($_GET['from'])) $from=$_GET['from'];
else $from=0;

if(isset($_GET['to'])) $to=$_GET['to'];
else $to=100;

if(isset($_GET['limit'])) $limit=$_GET['limit'];
else $limit=100;

if(isset($_GET['loop_num'])) $loop_num=$_GET['loop_num'];
else $loop_num=50;

if(isset($_GET['languish'])) $languish=$_GET['languish'];
else $languish=100;

printf("Date,persent,=>,best       ,fail       ,fine       ,$n");

 for($k=$from;$k<=$to;$k=$k+0.1){

 $percent=$k;

 $best=0;
 $fail=0;
 $fine=0;

 if($debug>1){
  echo "From: ", $from, $n;
  echo "To: ", $to, $n;
  echo "Limit: ", $limit, $n;
  echo "Percent: ", $percent, $n;
 } 
  
 for($j=0;$j<$loop_num;$j++){
  
  $max_num=0;
  $max_percent=$limit*$percent/100;
  $percent_num=0;
  $choice=0;
  
  $thisnum=range(1,$limit,1);//（小,大,差）
  shuffle($thisnum);//洗牌
  
   for($i=0;$i<$limit;$i++){
    //$num=rand($from, $to);
    $num=$thisnum[$i]*($limit-(($i+1)*$languish/100))/$limit;//設定此家店家價值
    if($max_num<$num) $max_num=$num;
     if($i<$max_percent) {
       if($percent_num<$num) $percent_num=$num;
     }
    if($debug>0) echo $i+1, " ", $num, $n;
    if($choice==0 and $num>$percent_num) $choice=$num;
   }
  
  if($debug>0){
   echo "Choice: ", $choice, $n;
   echo "Max: ", $max_num, $n;
  }
  
  if($max_num==$choice) $best++;
  if($choice==0) $fail++;
  if($max_num>$choice and $choice>0) $fine++;
  
 }  

 $thedate=date("m-d H:i");
 printf("%s,%.1f,=>,%.6f,%.6f,%.6f,(%.0f/%.0f)\n", $thedate, $percent, $best/$loop_num, $fail/$loop_num, $fine/$loop_num, log($limit, 10), log($loop_num, 10));
 
 } 

?>
