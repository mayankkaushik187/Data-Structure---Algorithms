bool canPair(vector < int > & arr, int k) {
  // An odd length array cannot be divided into pairs
  int n = arr.size();
  if (n & 1)
    return false;

  // Create a frequency array to count occurrences
  // of all remainders when divided by k.
  unordered_map < int, int > freq;

  // Count occurrences of all remainders
  for (int i = 0; i < n; i++)
    freq[((arr[i] % k) + k) % k]++;

  // Traverse input array and use freq[] to decide
  // if given array can be divided in pairs
  for (int i = 0; i < n; i++) {
    // Remainder of current element
    int rem = ((arr[i] % k) + k) % k;

    // If remainder with current element divides
    // k into two halves.
    if (2 * rem == k) {
      // Then there must be even occurrences of
      // such remainder
      if (freq[rem] % 2 != 0)
        return false;
    }

    // If remainder is 0, then there must be even 
    // number of elements with 0 remainder
    else if (rem == 0) {
      if (freq[rem] & 1)
        return false;
    }

    // Else number of occurrences of remainder
    // must be equal to number of occurrences of
    // k - remainder
    else if (freq[rem] != freq[k - rem])
      return false;
  }
  return true;
}
