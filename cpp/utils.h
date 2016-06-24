#pragma once

// Read in binary file to test
void read_file(const char* file_path){
	FILE* file = NULL;

	#ifdef VERBOSE
	printf("Opening file %s\n", file_path);
	#endif

	file = fopen(file_path, "rb");
	fread(data, 1, SIZE, file);
	fclose(file);

	#ifdef VERBOSE
	printf("Data read\n");
	#endif
}

// Fisher-Yates Fast (in place) shuffle algorithm
void shuffle(byte arr[]){
	srand(time(NULL));
	long int r;

	for(long int i = SIZE-1; i > 0; i--){
		r = rand() % (i+1);
		swap(arr[r], arr[i]);
	}
}

// Quick sum array
long int sum(byte arr[]){
	long int sum = 0;
	for(long int i = 0; i < SIZE; i++){
		sum += arr[i];
	}

	return sum;
}

// Quick sum vector
long int sum(vector<int> v){
	long int sum = 0;
	for(long int i = 0; i < v.size(); i++){
		sum += v[i];
	}

	return sum;
}

// Calculate baseline statistics
// Finds mean, median, and whether or not the data is binary
void calc_stats(){

	// Calculate mean
	mean = sum(data) / (long double) SIZE;

	// Sort in a vector for median/min/max
	vector<byte> v(data, data+SIZE);
	sort(v.begin(), v.end());

	byte min = v[0];
	byte max = v[SIZE-1];

	if(min == 0 && max == 1){
		is_binary = true;
		median = 0.5;
	}else{
		long int half = SIZE / 2;
		median = (v[half] + v[half-1]) / 2.0;
	}
}