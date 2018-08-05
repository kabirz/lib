#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

const char *fileName = "/dev/urandom";

int getRandomBytes(void *buf, size_t len)
{
	ifstream infile(fileName, ios::in);

	if (infile.is_open()) {
		infile.read((char *)buf, len);
		infile.close();
	} else {
		cerr << "error: the file " << fileName << " is not exist!" << endl;
		return -1;
	}
    return 0;
}

int main(int argc, char const *argv[])
{
	unsigned int buf[8] = { 0 };

	if (getRandomBytes(buf, sizeof(buf)) < 0)
		return -1;

	for (size_t i = 0; i < sizeof(buf) / sizeof(buf[0]); i++) {
		cout << " 0x" << setw(sizeof(buf[i]) * 2) << setfill('0') << hex << (int)buf[i];
	}
	cout << endl;
	return 0;
}
