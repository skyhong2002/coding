<?php

if (isset($argv))
    for ($i=1;$i<count($argv);$i++)
    {
        $it = explode("=",$argv[$i]);
        $_GET[$it[0]] = $it[1];
    }

$n="\n";
$brn="<br />\n";
$cr="\015";

date_default_timezone_set("Asia/Taipei");

if(isset($_GET['debug'])) $debug=$_GET['debug'];
else $debug=0;

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

for($k=0;$k<$limit;$k++){
  $besti[$k]=0;
  $alli[$k]=0;
}

$percent=$k;

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
$thisi=0;

$thisnum=range(1,$limit,1);//（小,大,差）
shuffle($thisnum);//洗牌

for($i=0;$i<$limit;$i++){
  //$num=$thisnum[$i]*($limit-$i+1)/$limit;
  $num=$thisnum[$i]*($limit-$i+1)/$limit;
  if($max_num<$num) {
    $max_num=$num;
    $thisi=$i;
  }
  $alli[$i]+=$num;
  $allall+=$num;
}
$besti[$thisi]++;

//if($j>0 and $j%10000==0){
//echo $cr;
//printf("%10d %.10f", $j, $best/$j);
//}

}

print_r($besti);
//print_r($alli);
?>
