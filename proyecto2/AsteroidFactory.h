#include "GameCommon.h"
#include <random>

bool initState;
std::mt19937 rng;

std::uniform_int_distribution<std::mt19937::result_type> nodeGenerator;
std::uniform_int_distribution<std::mt19937::result_type> asteroidGenerator;
std::uniform_int_distribution<std::mt19937::result_type> radioGenerator;

void initAsteroidFactory()
{
	initState = true;
	rng.seed(std::random_device()());
	nodeGenerator = std::uniform_int_distribution<std::mt19937::result_type>(MIN_ASTEROID_NODES,MAX_ASTEROID_NODES);
	asteroidGenerator = std::uniform_int_distribution<std::mt19937::result_type>(MIN_ASTEROID_COUNT,MAX_ASTEROID_COUNT);
	radioGenerator = std::uniform_int_distribution<std::mt19937::result_type>(MIN_ASTEROID_RADIO,MAX_ASTEROID_RADIO);
}

int nodeCount(){
	return nodeGenerator(rng);
}


int asteroidCount(){
	return asteroidGenerator(rng);
}

int nextRadio(){
	return radioGenerator(rng);
}
