#!/bin/bash
myfilename="100-250 250-500 500-1000 1000-2500 2500-4000 4000-6000 6000-Inf"
delphes=/home/dyilmaz/Desktop/UntitledFolder/delphes
cd $delphes
make
for say in $myfilename
do
 cd $delphes
 ./thesisnew combined_$say.root analysis_$say.root
done
cd $delphes
root -l << EOF
.L viacrossection.C
hadd()
.q
EOF
#cd $delphes
#root -l << EOF
#.L analysis.C
#calc()
#.q
#EOF


exit 0
