
source a.sh
cp ./stuff/r.sh ../r.sh

cd .. # go basck to ../cp

touch i
source r.sh
echo "cp folder has:"
ls cp/
