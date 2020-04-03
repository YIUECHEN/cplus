#pragma once
#include<vector>
#include<assert.h>

using namespace std;

template<size_t N>
class BitSet{
public:

	BitSet(){
		_bs.resize((N >> 3) + 1);
	}

	BitSet<N>& set(size_t num){
		assert(num < N);
		int index = num >> 3;
		int pos = num % 8;
		_bs[index] |= (1 << pos);
		return *this;
	}

	BitSet<N>& reset(size_t num){
		assert(num < N);
		int index = num >> 3;
		int pos = num % 8;
		_bs[index] &=~(1 << pos);
		return *this;
	}
	size_t size()const{
		return N;
	}
	size_t count()const{
		int bitCnttable[256] = {
			0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4, 1, 2, 2, 3, 2, 3, 3, 4, 2,
			3, 3, 4, 3, 4, 4, 5, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3,
			3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3,
			4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 2, 3, 3, 4,
			3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5,
			6, 6, 7, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4,
			4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5,
			6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 2, 3, 3, 4, 3, 4, 4, 5,
			3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 3,
			4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6,
			6, 7, 6, 7, 7, 8 };

		size_t getcount=0;

		for (auto e : _bs){
			getcount += bitCnttable[e];
		}
		return getcount;
	}

	bool test(size_t num)const{
		assert(num < N);
		int index = num >> 3;
		int pos = num % 8 ;
		
		return (_bs[index] & (1 << pos)) != 0;
	}

private:
	vector<unsigned char> _bs;
};