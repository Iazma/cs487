// Neural Network Prototype
// Group 8 CSCI 48700

#include <vector>
#include <iostream>
#include <cstdlib>
#include <cassert>

// I know its bad to use namespaces, but I'm lazy right now - Cory
using namespace std;

class Neuron {};
typedef vector<Neuron> Layer;

// *********************** class Neuron *********************

class Neuron{
	public:
		Neuron(unsigned numOutputs);
	private:
		static double randomWeight(void) {return rand() / double(RAND_MAX);}
		double m_outputVal;
}

Neuron::Neuron(unsigned numOutputs){
	for(unsigned c = 0; c < numOutputs; ++c){
		m_outputWeights.push_back(Connection());
		// random weight value
		m_outputWeights.back().weight = randomWeight();
	}
}

// *********************** class Net *********************
class Net {
	public:
		Net(const vector<unsigned> &topology);
		void feedForward(const vector<double> &inputVals) {};
		void backPropogation(const vector<double> &targetVals) {};
		void getResults(vector<double> &resultVals) const {};
	
	private:
		vector<Layer> m_layers; // m_layers[layerNum][neuronNum]
};

void Net::feedForward(const vector<double> &inputVals){
	assert(inputVals.size() = m_layers[0].size() - 1);
	
	// Assign the input values into the input Neurons
	for(unsigned i = 0; i < inputVals.size(); ++i){
		m_layers[0][i].m_outputVal = 
	}
}

Net::Net(const vector<unsigned> &topology){
	
	unsigned numLayers = topology.size();
	for(unsigned layerNum = 0; layerNum < numLayers; ++layerNum){
		m_layers.push_back(Layer());
		unsigned numOutputs = layerNum == topology.size() - 1 ? 0 : topology[layerNum + 1];
		
		// We have a new Layer, now fill it with neurons, and
		// add a bias neuron to the layer
		for(unsigned neuronNum = 0; neuronNum <= topology[layerNum]; ++neuronNum){
			// Create a new Neuron
			m_layers.back().push_back(Neuron());
			cout << "Made a Neuron!" << endl;
		}
	}
}

int main(){
	
	vector<unsigned> topology;
	topology.push_back(3);
	topology.push_back(2);
	topology.push_back(1);
	
	Net myNet(topology);
	
	vector<double> inputVals;
	myNet.feedForward(inputVals);
	
	vector<double> targetVals;
	myNet.backPropogation(targetVals);
	
	vector<double> resultVals;
	myNet.getResults(resultVals);

}

