# General instructions

This test checks for error handling and memory leaks for these error cases using valgrind. To run it:

- run `make` in your project folder
- edit `MINIRT_PATH` variable in `error_test.sh` to the path to your `miniRT`

## Error tests

- run `./error_test.sh`

## Valgrind tests

To check leaks in error handling run `./error_test.sh valgrind`
