#!/bin/bash


sz=/g/g90/wang116/softwares/library/SZ/build/bin/sz
zfp=/g/g90/wang116/softwares/library/zfp/build/bin/zfp
fpzip=/g/g90/wang116/softwares/library/fpzip/build/bin/fpzip

nx=8136

rm *.sz* *.zfp* *.tar.gz *.fpzip*
# sz
# -R relative error bound, set to 0 for lossless?
$sz -z -d -i ./durations.dat -1 $nx -M REL -R 0
$sz -z -d -i ./intervals.dat -1 $nx -M REL -R 0

# 2. zfp
# -d double, -R lossless, -1 [nx], -z output compressed file
$zfp -d -i ./durations.dat -R -1 $nx -z ./durations.dat.zfp
$zfp -d -i ./intervals.dat -R -1 $nx -z ./intervals.dat.zfp

# 3. fpzip
$fpzip -t double -i ./durations.dat -o ./durations.dat.fpzip -1 $nx
$fpzip -t double -i ./intervals.dat -o ./intervals.dat.fpzip -1 $nx

# 4. gzip
tar -czvf ./durations.tar.gz ./durations.dat
tar -czvf ./intervals.tar.gz ./intervals.dat
