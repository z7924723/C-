# User Defined Literals

## Define

Literals are the values of a program which have a fixed value. There are five types of literals in C++.

1. Integer Literals :

   ```C++
   int decimal = 123; // Decimal
   int octal = 0175; // Octal
   int hexa = 0xa1b; // Hexadecimal
   ```

2. Floating Point Literals :

   ```c++
   float a = 30.152;
   ```

3. Boolean Literals :

   ```C++
   bool var = true;
   ```

4. Character Literals :

   ```C++
   char s = ‘a’;
   ```

5. String Literals :

6. ```C++
   char s[] = “hello”;
   ```
------
## Suffix of literals

```C++
45  // int literal
45u // unsign literal
45l // long literal
```
------
## Restriction
The following parameter lists are allowed on literal operators :
```C++
( const char * )
( unsigned long long int )	
( long double )	
( char )
( wchar_t )	
( char16_t )	
( char32_t )	
( const char * , std::size_t )	
( const wchar_t * , std::size_t )	
( const char16_t * , std::size_t )		
( const char32_t * , std::size_t )	
```
