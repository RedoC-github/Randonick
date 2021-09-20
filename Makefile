randonick:
		g++ -o ~/randonick randonick.cpp -std=c++11 | alias randonick="~/randonick"

test:
		./randonick < ci-test

clear:
		rm ~/randonick