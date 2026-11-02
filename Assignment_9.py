# Function to check if pattern matches text at a specific shift index
def checkMatchAtShift(text, pattern, shift):
   m = len(pattern)
   for j in range(m):
       if text[shift + j] != pattern[j]:
           return False
   return True
# Naive String Matching Algorithm to find all starting indices
def naiveStringMatch(text, pattern):
   n = len(text)
   m = len(pattern)
   matchingIndices = []
   # Check constraint: 0 <= m <= n
   if m > n:
       print("Invalid input: Pattern length is greater than Text length.")
       return matchingIndices
   if m == 0:
       print("Empty pattern matches at index 0.")
       return [0]
   # Slide pattern window one character at a time from index 0 to n - m
   for i in range(n - m + 1):
       isMatch = checkMatchAtShift(text, pattern, i)
       if isMatch:
           matchingIndices.append(i)
   return matchingIndices
# Function to display matching results clearly
def displayMatchResults(text, pattern):
   print("Text String (n =", len(text), ")   :", text)
   print("Pattern String (m =", len(pattern), "):", pattern)
   indices = naiveStringMatch(text, pattern)
   if len(indices) > 0:
       print("Pattern found at starting indices:", indices)
       print("Total Occurrences Found:", len(indices))

       for idx in indices:
           matchedSubstr = text[idx : idx + len(pattern)]
           print(" -> Index", idx, ": text[", idx, ":", idx + len(pattern), "] =", matchedSubstr)
   else:
       print("Pattern not found in the given text.")
   print()
# Driver Code testing multiple cases
if __name__ == "__main__":
   # Test Case 1: Standard text with multiple occurrences
   text1 = "AABAACAADAABAABA"
   pattern1 = "AABA"
   print("--- Test Case 1 ---")
   displayMatchResults(text1, pattern1)
   # Test Case 2: Alphanumeric string with digits and underscores
   text2 = "SPPU_2024_DSA_2024_LAB"
   pattern2 = "2024"
   print("--- Test Case 2 ---")
   displayMatchResults(text2, pattern2)
   # Test Case 3: Overlapping pattern occurrences
   text3 = "AAAAA"
   pattern3 = "AA"
   print("--- Test Case 3 ---")
   displayMatchResults(text3, pattern3)
