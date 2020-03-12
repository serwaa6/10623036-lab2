	#include <iostream>
#include "mpi.h"
#include <chrono>
using namespace std;
using namespace std::chrono;
int main(int argc, char* argv[]){

MPI::Init(argc, argv);
int rank,size,sum = 0;
int numberprocess,processid;

size = MPI::COMM_WORLD.Get_size();
rank = MPI::COMM_WORLD.Get_rank();


startval = 1000*rank/size+1;
endval = 1000*(rank +1)/size;
for(int i = startval; i<endval; i ++){
sum = sum +1;}
if(rank !=0){
   
MPI::COMM_WORLD.Send(&sum, 1, MPI::INT, rank-1,1);
cout<< "rank-1 receiving from "<< rank << endl;
                              
}else{sum = sum}

if(rank == size-1){

MPI::COMM_WORLD.Send(&sum,1,MPI::INT,0,1);

}
 if(rank==size-1){

MPI::COMM_WORLD.Recv(&sum,1,MPI::INT,size-1,1);
}

MPI::Finalize();
return 0; 
}
