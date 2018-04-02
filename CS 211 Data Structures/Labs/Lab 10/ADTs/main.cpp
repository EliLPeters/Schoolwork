#include <iostream>

#include "examples\hashtables.h"
#include "NewHasher.h"

using namespace std;

int main(void)
{
	//BucketHashTable<string, string> bht{ new SimpleStringHasher{} };
	//LinearHashTable<string, string> lht{ new SimpleStringHasher{} };
	//QuadraticHashTable<string, string> qht{ new SimpleStringHasher{} };
	//DoubleHashTable<string, string> dht{ new SimpleStringHasher{} };

	BucketHashTable<string, string> bht{ new NewHasher{} };
	LinearHashTable<string, string> lht{ new NewHasher{} };
	QuadraticHashTable<string, string> qht{ new NewHasher{} };
	DoubleHashTable<string, string> dht{ new NewHasher{} };

	cout << "Running bucket hash on 2000 elements: "
		<< exampleBenchmark(bht, 2000) << endl;
	cout << "Running linear hash on 2000 elements: "
		<< exampleBenchmark(lht, 2000) << endl;
	cout << "Running quadratic hash on 2000 elements: "
		<< exampleBenchmark(qht, 2000) << endl;
	cout << "Running double hash on 2000 elements: "
		<< exampleBenchmark(dht, 2000) << endl;


	/*for (auto item : bht.getKeys())
	{
		cout << item << endl;
	}*/
    return 0;
}