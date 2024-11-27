# Example script for compiling ZBC library
gcc -c complex.c -o complex.o
gcc -c model_IHC.c -o model_IHC.o
gcc -c model_Synapse.c -o model_Synapse.c
gcc -shared -o libzbc2014.so model_IHC.o model_Synapse.o complex.o
