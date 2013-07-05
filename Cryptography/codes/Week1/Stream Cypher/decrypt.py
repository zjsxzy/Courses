# Coursera - Cryptography I Assignment 1
# Takes 11 encrypted messages using the same key as input
# Outputs the plain message (decrypted) of the last messageas its result
def crypt_PS1():
  
  # Function which decrypts the ith byte of the last message and returns the character
  def decrypt(ithChar):

    # Array to store the number of occurrences of xor'ed msgs resulting in [a-zA-Z]
    numOcc = [] 
    for i in xrange(len(asciiTexts)):
      numOcc.append(0)

    # XOR each message with every other message
    for i in xrange(len(asciiTexts)):
      for j in xrange(len(asciiTexts)):
        if j != i:
          # XOR'ed byte for the two messages
          xorChar = asciiTexts[i][ithChar] ^ asciiTexts[j][ithChar]
          # If XOR'ed byte is [a-zA-Z], then one of the bytes is a space character
          if (xorChar in range(65,91) or xorChar in range(97, 123)):
            numOcc[i] += 1
    
    # Find highest occurrence of space character among all messages for corresponding byte
    # maxOcc[0] is the ith sg, maxOcc[1] is the # of occurrences
    maxOcc = [0,0]
    for i in xrange(len(numOcc)):
      if numOcc[i] > maxOcc[1]:
        maxOcc = [i,numOcc[i]]

    # XOR the byte with highest probability of being a space character with the message we wish to decode
    xorChar = asciiTexts[maxOcc[0]][ithChar] ^ asciiTexts[len(asciiTexts) - 1][ithChar]

    # Return the decoded character XOR'ed with a space character to obtain the proper case
    return chr(xorChar ^ 32)

  # Inputs of cipher texts in .txt
  fi = open('ciphertexts.txt', 'r')

  cipherTexts = [] # Where we store the inputs
  asciiTexts = []  # Where we covert the inputs to ascii bytes (2D Array)

  # Store inputs into cipherTexts, and prepare proper size of asciiTexts
  for line in fi:
    cipherTexts.append(line);
    asciiTexts.append([]);

  # For each cipher text
  for i in xrange(len(cipherTexts)):
    # For each byte of the cipher text
    for j in range(len(cipherTexts[i]) - 1)[::2]:
      # Store the ascii format of the byte
      asciiTexts[i].append(int(cipherTexts[i][j] + cipherTexts[i][j+1], 16))

  # Print out the messages in ASCII, grouped into bytes
  for a in asciiTexts:
    print a , '\n'

  # Where we store the decrypted message
  decryptedMsg = ""

  # For each byte of the msg to decrypt, decrypt then store into variable
  for i in xrange(len(asciiTexts[len(asciiTexts) - 1])):
    decryptedMsg += decrypt(i)

  # print out decrypted message
  print decryptedMsg


if __name__ == "__main__":
  crypt_PS1()