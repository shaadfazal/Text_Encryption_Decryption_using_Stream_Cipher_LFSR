# Text_Encryption_Decryption_using_Stream_Cipher_LFSR
Using the C file 'main.c' text file is read and a key is generated of the same bit length as the plaintext using one time pad principle and is used to encrypt the plaintext and then decrypt it to get the original plaintext back
In this code plaintext is read from a text file 'ma.txt', character by character and converted into its corresponding bitstream and encrypted by XOR'ing using a bistream key generated by a stream cipher. Then the bits are grouped to give back the ASCII characters and written into the file 'ea.txt'
Then the encrypted bitstream can again be XOR'ed again to give back the original message to indicate successful decryption and the decrypted text is also writeen into the file 'ea.txt' 
