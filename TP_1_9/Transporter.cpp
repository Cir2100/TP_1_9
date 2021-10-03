#include "Transporter.h"

Transporter::Transporter(MyArray<Plane> _planes, MyArray<Car> _cars, MyArray<Train> _trains) :
	planes(_planes), cars(_cars), trains(_trains)
	{ Logger::printBuilder("Transporter"); }

Transporter::Transporter(const Transporter& transporter) :
	planes(transporter.planes), cars(transporter.cars), trains(transporter.trains)
	{ Logger::printCopyBuilder("Transporter"); }

void Transporter::addObject(Plane& plane) { planes.add(plane); }
void Transporter::addObject(Car& car) { cars.add(car); }
void Transporter::addObject(Train& train) { trains.add(train); }

void Transporter::changeObject(Plane& plane, int index) { planes[index] = plane; }
void Transporter::changeObject(Car& car, int index) { cars[index] = car; }
void Transporter::changeObject(Train& train, int index) { trains[index] = train; }

void Transporter::deletePlane(int index) { planes.del(index); }
void Transporter::deleteCar(int index) { cars.del(index); }
void Transporter::deleteTrain(int index) { trains.del(index); }


void Transporter::inputFromConsole() {
	std::cout << "Введите количество самолетов: ";
	int count = processingInput(0, INT32_MAX);
	for (int i = 0; i < count; i++) {
		Plane plane;
		plane.inputFromConsole();
		addObject(plane);
	}

	std::cout << "Введите количество автомобилей: ";
	count = processingInput(0, INT32_MAX);
	for (int i = 0; i < count; i++) {
		Car car;
		car.inputFromConsole();
		addObject(car);
	}

	std::cout << "Введите количество поездов: ";
	count = processingInput(0, INT32_MAX);
	for (int i = 0; i < count; i++) {
		Train train;
		train.inputFromConsole();
		addObject(train);
	}
}

void Transporter::inputFromFile(std::string filename) {
	std::ifstream file(filename);
	std::string tmpString;
	int countLines = 0;
	bool isInput = false;
	while (!file.eof()) {
		if (!isInput) {
			if (std::getline(file, tmpString))
				countLines++;
			else
				break;				
		}
		if (contains(tmpString, PLANE_STRING)) {
			isInput = true;
			Plane plane;
			plane.inputFromFile(file, tmpString, countLines);
			addObject(plane);
		}
		else if (contains(tmpString, CAR_STRING)) {
			isInput = true;
			Car car;
			car.inputFromFile(file, tmpString, countLines);
			addObject(car);
		}
		else if (contains(tmpString, TRAIN_STRING)) {
			isInput = true;
			Train train;
			train.inputFromFile(file, tmpString, countLines);
			addObject(train);
		}
		else
			isInput = false;
	}
	file.close();
}

void Transporter::inputFromCodeFile(std::string filename) {
	Decoder decoder(filename);
	decoder.decodeLZ77();
	inputFromFile("tmp.txt");
	remove("tmp.txt");
}

void Transporter::print(std::ostream& out, std::string type) {
	std::string splitter = " ";
	if (type == ".csv")
		splitter = ";";
	if (planes.getSize() > 0 || cars.getSize() > 0 || trains.getSize() > 0) {
		out << "Список объектов:" << std::endl;
		printPlanes(out, splitter);
		printCars(out, splitter);
		printTrains(out, splitter);
	}
	else
		out << "У грузоперевозчика нет объектов" << std::endl;
}

void Transporter::codeToFile(std::string filename) {
	Coder coder(filename);
	for (int i = 0; i < planes.getSize(); i++) {
		coder.encodeBlocLZ77(planes[i].toStringArray(std::to_string(i + 1)));
	}
	for (int i = 0; i < cars.getSize(); i++) {
		coder.encodeBlocLZ77(cars[i].toStringArray(std::to_string(i + 1)));
	}
	for (int i = 0; i < trains.getSize(); i++) {
		coder.encodeBlocLZ77(trains[i].toStringArray(std::to_string(i + 1)));
	}
}

void Transporter::printPlanes(std::ostream& out, std::string splitter) {
	for (int i = 0; i < planes.getSize(); i++)
		planes[i].print(out, " " + std::to_string(i + 1), splitter);
}

void Transporter::printCars(std::ostream& out, std::string splitter) {
	for (int i = 0; i < cars.getSize(); i++)
		cars[i].print(out, " " + std::to_string(i + 1), splitter);
}

void Transporter::printTrains(std::ostream& out, std::string splitter) {
	for (int i = 0; i < trains.getSize(); i++)
		trains[i].print(out, " " + std::to_string(i + 1), splitter);
}

Transporter& Transporter::operator=(const Transporter& transporter)
{
	if (this == &transporter)
		return *this;
	planes = transporter.planes;
	cars = transporter.cars;
	trains = transporter.trains;
	return *this;
}