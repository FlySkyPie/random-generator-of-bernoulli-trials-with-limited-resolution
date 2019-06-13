<?php
exec('g++ test1.cpp ./../BernoulliJudge.cpp -o test1');
exec('g++ test2.cpp -o test2');
exec('./test1');
exec('./test2');