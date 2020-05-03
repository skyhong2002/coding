<?php

if (isset($argv))
    for ($i=1;$i<count($argv);$i++){
        $it = explode("=",$argv[$i]);
        $_GET[$it[0]] = $it[1];
    }

$n="\n";
$brn="<br />\n";

date_default_timezone_set("Asia/Taipei");

//設定變數

//尋找隨機取的期望值

if(isset($_GET['debug'])) $debug=$_GET['debug'];
else $debug=1;

if(isset($_GET['limit'])) $limit=$_GET['limit'];
else $limit=1000;

if(isset($_GET['loop_num'])) $loop_num=$_GET['loop_num'];
else $loop_num=100;

if(isset($_GET['loop_num1'])) $loop_num1=$_GET['loop_num1'];
else $loop_num1=10;


$total_score=0;
for($i=0;$i<$loop_num1;$i++)
{
 $score=0;

 for($j=0;$j<$loop_num;$j++)
 {
  $choice=0;
  $thisnum=range(1,$limit,1);//（小,大,差）
  shuffle($thisnum);//洗牌
  $y=rand(1,$limit);
  $choice=$thisnum[$y];
  $score=$score+$choice;
 }  
 $score=$score/$loop_num;
 if($debug>0)
 {
  printf("%6.f $n",$score);
 }
 
$total_score=$total_score+$score;
}
$total_score=$total_score/$loop_num1;
printf("%6.f $n",$total_score);

?>
