/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function(s) {
    // Split the input string into an array of words using space as the delimiter
    const words = s.split(' ');

    // Iterate through each word in the array
    for (let i = 0; i < words.length; i++) {
        // Split the current word into an array of characters, reverse the array, and join it back into a string
        words[i] = words[i].split('').reverse().join('');
    }

    // Join the array of reversed words into a string, separating them with spaces
    return words.join(' ');
};
