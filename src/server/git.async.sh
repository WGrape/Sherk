echo "---------- 开始同步";

cd SherkEngine; git add .; git commit -m 'random_'$RANDOM; git push origin; echo "---------- SherkEngine同步到GitHub成功"; cd ..

cd SherkLaunch; git add .; git commit -m 'random_'$RANDOM; git push origin; echo "---------- SherkLaunch同步到GitHub成功"; cd ..

cd SherkLink; git add .; git commit -m 'random_'$RANDOM; git push origin; echo "---------- SherkLink同步到GitHub成功"; cd ..

cd SherkMechanism; git add .; git commit -m 'random_'$RANDOM; git push origin; echo "---------- SherkMechanism同步到GitHub成功"; cd ..

cd SherkSQL; git add .; git commit -m 'random_'$RANDOM; git push origin; echo "---------- SherkSQL同步到GitHub成功"; cd ..

cd SherkStorage; git add .; git commit -m 'random_'$RANDOM; git push origin; echo "---------- SherkStorage同步到GitHub成功"; cd ..

cd SherkSupport; git add .; git commit -m 'random_'$RANDOM; git push origin; echo "---------- SherkSupport同步到GitHub成功"; cd ..

cd SherkSystem; git add .; git commit -m 'random_'$RANDOM; git push origin; echo "---------- SherkSystem同步到GitHub成功"; cd ..

git add .; git commit -m 'random_'$RANDOM; git push origin; echo "---------- Sherk同步到GitHub成功"

echo "---------- 同步结束"