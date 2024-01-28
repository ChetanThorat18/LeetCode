# Dry Run 
## input  s =  " 10 + (4+5+2) - 3 + (6+8) "

## Initialization:
- result = 0
- number = 0
- sign = 1
- Stack: Empty

## Iteration 1 (s[0] = '1'):
- `isdigit(s[0])` is true, so update number = 1.

## Iteration 2 (s[1] = '0'):
- `isdigit(s[1])` is true, so update number = 10.

## Iteration 3 (s[2] = '+'):
- Since it's '+':
  - result += number * sign (0 + 10 * 1 = 10).
  - Reset number = 0 and set sign = 1.

## Iteration 4 (s[3] = '('):
- Push current result (10) and sign (1) onto the stack.
- Reset result = 0, number = 0, and set sign = 1.

## Iteration 5 (s[4] = '4'):
- `isdigit(s[4])` is true, so update number = 4.

## Iteration 6 (s[5] = '+'):
- Since it's '+':
  - result += number * sign (0 + 4 * 1 = 4).
  - Reset number = 0 and set sign = 1.

## Iteration 7 (s[6] = '5'):
- `isdigit(s[6])` is true, so update number = 5.

## Iteration 8 (s[7] = '+'):
- Since it's '+':
  - result += number * sign (4 + 5 * 1 = 9).
  - Reset number = 0 and set sign = 1.

## Iteration 9 (s[8] = '2'):
- `isdigit(s[8])` is true, so update number = 2.

## Iteration 10 (s[9] = ')'):
- Add the current result to the previous result on the stack with the current sign.
  - result += number * sign (9 + 2 * 1 = 11).
- Pop from the stack: prevResult = 10, prevSign = 1.
- Update result with the new calculated result (11 + 10 * 1 = 21).

## Iteration 11 (s[10] = '-'):
- Since it's '-':
  - result += number * sign (21 + 0 * -1 = 21).
  - Reset number = 0 and set sign = -1.

## Iteration 12 (s[11] = '3'):
- `isdigit(s[11])` is true, so update number = 3.

## Iteration 13 (s[12] = '+'):
- Since it's '+':
  - result += number * sign (21 + 3 * -1 = 18).
  - Reset number = 0 and set sign = 1.

## Iteration 14 (s[13] = '('):
- Push current result (18) and sign (1) onto the stack.
- Reset result = 0, number = 0, and set sign = 1.

## Iteration 15 (s[14] = '6'):
- `isdigit(s[14])` is true, so update number = 6.

## Iteration 16 (s[15] = '+'):
- Since it's '+':
  - result += number * sign (0 + 6 * 1 = 6).
  - Reset number = 0 and set sign = 1.

## Iteration 17 (s[16] = '8'):
- `isdigit(s[16])` is true, so update number = 8.

## Iteration 18 (s[17] = ')'):
- Add the current result to the previous result on the stack with the current sign.
  - result += number * sign (6 + 8 * 1 = 14).
- Pop from the stack: prevResult = 18, prevSign = 1.
- Update result with the new calculated result (14 + 18 * 1 = 32).

## After the Loop:
- The loop ends, but there's one more step to add the last number to the result with the current sign.
  - result += number * sign (32 + 0 * 1 = 32).

## Final Result:
- The final result is 32.

