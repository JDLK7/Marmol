TESTSPORO=25
TESTSVECTOR=18
TESTSTLISTA=12
nombreBase="tad"
extension=".cpp"
zero="0"

echo "Autocorrector Cuadernillo 1 PED"
echo "1. Test TPoro"
echo "2. Test TVectorPoro"
echo "3. Test TListaPoro"
echo "4. Todos"
echo 'Opcion: '
read Opcion
if (( $Opcion == 1 || $Opcion == 4 )); then
	
	echo "//////////////////////////////////////////////////////////////////"
	echo "///////////////////////Pruebas TPoro//////////////////////////////"
	cp src/tporo/*.cpp src/
	for (( i = 1; i <= $TESTSPORO; i++ )); do
		
		if (($i >= 10)); then
			nombre=$nombreBase$i$extension 
		else
			nombre=$nombreBase$zero$i$extension 
		fi
		echo $nombre
		mv src/$nombre src/tad.cpp
		make > basura.txt
		./tad > $i.txt
		diff -b $i.txt salidas/tporo/$nombre.sal
		mv src/tad.cpp src/$nombre
		rm ./tad
		rm ./basura.txt
		rm $i.txt
		
	done
	rm src/*.cpp
fi
if (( $Opcion == 2 || $Opcion == 4 )); then

	echo "//////////////////////////////////////////////////////////////////"
	echo "//////////////////////Pruebas TVectorPoro/////////////////////////"
	cp src/tvectorporo/*.cpp src/
	for (( i = 1; i <= $TESTSVECTOR; i++ )); do
		
		if (($i >= 10)); then
			nombre=$nombreBase$i$extension 
		else
			nombre=$nombreBase$zero$i$extension 
		fi
		echo $nombre
		mv src/$nombre src/tad.cpp
		make > basura.txt
		./tad > $i.txt
		diff -b $i.txt salidas/tvectorporo/$nombre.sal
		mv src/tad.cpp src/$nombre
		rm ./tad
		rm ./basura.txt
		rm $i.txt
		
	done
	rm src/*.cpp
fi
if (( $Opcion == 3 || $Opcion == 4 )); then
	echo "//////////////////////////////////////////////////////////////////"
	echo "///////////////////////Pruebas TListaPoro/////////////////////////"
	cp src/tlistaporo/*.cpp src/
	for (( i = 1; i <= $TESTSTLISTA; i++ )); do
		
		if (($i >= 10)); then
			nombre=$nombreBase$i$extension 
		else
			nombre=$nombreBase$zero$i$extension 
		fi
		echo $nombre
		mv src/$nombre src/tad.cpp
		make > basura.txt
		./tad > $i.txt
		diff -b $i.txt salidas/tlistaporo/$nombre.sal
		mv src/tad.cpp src/$nombre
		rm ./tad
		rm ./basura.txt
		rm $i.txt
		
	done
	rm src/*.cpp
fi
