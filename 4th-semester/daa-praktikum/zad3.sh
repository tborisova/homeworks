counter=`ls *.cpp | wc -l`
echo $counter
if test $counter -gt 20
then touch sources.txt
for i in `ls $1 | grep *.cpp`
do
 $i > sources
done
else
 echo "not enough files"
fi 
