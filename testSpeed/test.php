<?php
exec('g++ test1.cpp ./../BernoulliJudge.cpp -o test1');
exec('g++ test2.cpp -o test2');

$executionStartTime = microtime(true);
exec('./test1');
$executionEndTime = microtime(true);
$seconds = $executionEndTime - $executionStartTime;
echo "The test1 took $seconds to execute.\n";


$executionStartTime = microtime(true);
exec('./test2');
$executionEndTime = microtime(true);
$seconds = $executionEndTime - $executionStartTime;
echo "The test2 took $seconds to execute.\n";
