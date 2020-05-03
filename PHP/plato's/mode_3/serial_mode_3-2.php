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
//mode=3 競爭 v(分數) 同limit 
//mode=4 參考

if(isset($_GET['debug'])) $debug=$_GET['debug'];
else $debug=1;//顯示步驟

if(isset($_GET['PR_from'])) $PR_from=$_GET['PR_from']; //PR
else $PR_from=90;

if(isset($_GET['PR_gap'])) $PR_gap=$_GET['PR_gap'];
else $PR_gap=1;

if(isset($_GET['PR_to'])) $PR_to=$_GET['PR_to'];
else $PR_to=100;

if(isset($_GET['limit'])) $limit=$_GET['limit'];
else $limit=100;

if(isset($_GET['get_from'])) $get_from=$_GET['get_from']; //t%
else $get_from=25;

if(isset($_GET['get_gap'])) $get_gap=$_GET['get_gap'];
else $get_gap=1;

if(isset($_GET['get_to'])) $get_to=$_GET['get_to'];
else $get_to=35;

if(isset($_GET['loop_num'])) $loop_num=$_GET['loop_num'];
else $loop_num=10000;


printf("Date,percent\get,=>");
for($a=$get_from;$a<=$get_to;$a=$a+$get_gap){
printf(",$a");
}
printf("$n");


for($k=$PR_from;$k<=$PR_to;$k=$k+$PR_gap)
{
 $thedate=date("m-d H:i");
 $percent=$k;
 printf("%s,%s,=>", $thedate, $percent);
 $total_score=0;

 
 for($p=$get_from;$p<=$get_to;$p=$p+$get_gap){
$get=$p;

 if($debug>1)
 {
  echo "From: ", $from, $n;
  echo "To: ", $to, $n;
  echo "Limit: ", $limit, $n;
  echo "Percent: ", $percent, $n;
 } 
  
 for($j=0;$j<$loop_num;$j++)
 {
  $choice_time=1;
  $max_num=0;
  $choice=0;
  $score=0;
  $percent_get=$limit*$get/100;
  $percent_PR=$percent/100;
  $thisnum=range(1,$limit,1);//（小,大,差）
  shuffle($thisnum);//洗牌
  
   for($i=0;$i<$limit;$i++)//選擇
   { 
    $num=$thisnum[$i];
    if($max_num<$num) $max_num=$num;
   
    $pos=0;
    $num_PR=0;
    for($m=0;$m<$i;$m++)//決定大小排列
    {
     if($num>$thisnum[$m]) $pos=$pos+1;
    }
    if($i>$percent_get)$num_PR=$pos/$i;
    if($debug>0) echo $i+1, " ", $num, " ", $num_PR, $n;
     if($num_PR>$percent_PR and $choice_time>0){
      $choice=$num;
      $choice_time=$choice_time-1;
     }
   }
  if($choice_time>0){
     $choice=$num;
     $choice_time=$choice_time-1;
    }
  $score=$choice;
  $total_score=$total_score+$score;
  
  if($debug>0){
   echo "Choice: ", $choice, $n;
   echo "Max: ", $max_num, $n;
   echo "choice_time: ", $choice_time, $n;
  }
  
 }  
 
 $total_score=$total_score/$loop_num;
 printf(",%.7f", $total_score*(100/$limit));

} 

printf("$n");

}

?>