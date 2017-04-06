# cx_hash
Hashing a string during compile time.

### Description
Compatible (tested) with Visual Studio 2017's std::hash<string>.
Can be used also cross-platform, but it's not guaranteed to be compatible with std::hash<string> as each implementation can vary.

#### Enables developers to do things like below, in an efficient manner:

```
string value = "some string";
switch (cx_hash(value.c_str())) { // runtime hashing
case cx_hash("a"): // compile time hashing
	cout << "a found!\n";
	break;
	.
	.
	.
case cx_hash("some string"): // compile time hashing
	cout << "some string hash found!\n";
	break;
}
```

#### Output:
```
some string hash found!
```
