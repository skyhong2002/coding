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

if(isset($_GET['debug'])) $debug=$_GET['debug'];
else $debug=1;

if(isset($_GET['from'])) $from=$_GET['from'];
else $from=0;

if(isset($_GET['to'])) $to=$_GET['to'];
else $to=100;

if(isset($_GET['limit'])) $limit=$_GET['limit'];
else $limit=100;

if(isset($_GET['percent'])) $percent=$_GET['percent'];
else $percent=50;

if(isset($_GET['loop_num'])) $loop_num=$_GET['loop_num'];
else $loop_num=50;

if($debug>1){
echo "From: ", $from, $n;
echo "To: ", $to, $n;
echo "Limit: ", $limit, $n;
echo "Percent: ", $percent, $n;
echo "Border: ", $limit*$percent/100, $n;
}

$best=0;
$fail=0;
$fine=0;

for($j=0;$j<$loop_num;$j++){

$max_num=0;
$max_percent=$limit*$percent/100;
$percent_num=0;
$choice=0;

for($i=0;$i<$limit;$i++){
  $num=rand($from, $to);
  if($max_num<$num) $max_num=$num;
  if($i+1<=$max_percent) {
    if($percent_num<$num) $percent_num=$num;
    //echo "P:", $percent_num, $n;
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

//echo $n;
echo "Best: ", $best, $n;
echo "Fail: ", $fail, $n;
echo "Fine: ", $fine, $n;

?>
