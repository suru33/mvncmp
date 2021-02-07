# Maven Version Comparator

Compare maven release versions

### Examples

```shell

~$ mvncmp "1.0-alpha1" "1.0-beta1"
-1  

~$ mvncmp "1.0" "1.0-beta1"
1

~$ mvncmp "1.0-final" "1.0"
0
