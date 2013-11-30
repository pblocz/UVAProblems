#include <vector>
int main(){
    std::vector<int> v;
    for(int i=0;i<10000000;i++){
	v.push_back(i);
    }
    return 0;
}
