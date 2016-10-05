team=1
nbr=($1)
let nbr=nbr+1
ctr=0

if [ $# -gt 3 ]; then
    echo "Usage: ./launch [number of teams] [number of players by teams] -g [graphic]"
    exit
fi

while [ $team -lt $nbr ]; do
    count=0
    while [ $count -lt $2 ]; do
	if [ $ctr -gt 10000 ];then
	    echo "WARNING too much players"
	else
	    echo "launch ./lemipc -t "$team $3
	    ./lemipc -t $team $3 &
	fi
	let count=count+1
	let ctr=ctr+1
    done
    	let team=team+1
done
