for x in a b c d e f; do
	echo $x
	./pro < $x.in > $x.out
done
