# test_hotdoc

This is a test project for [hotdoc](https://github.com/hotdoc/hotdoc).
Its purpose is to exercise as many of hotdoc's capabilities in as little
code as possible.

The reference output is visible at <https://people.collabora.com/~meh/test_hotdoc/index.html>

## Building it

### System-wide dependencies

On Fedora:

```
dnf install graphviz-devel python-devel libxml2-devel libxslt-devel cmake libyaml-devel meson clang-devel llvm-devel flex
```

And on Ubuntu / Debian:

```
apt-get install libgraphviz-dev python-dev libxml2-dev libxslt1-dev cmake libyaml-dev meson libclang-dev llvm-dev flex
```

### Python dependencies

```
pip2 install virtualenv
virtualenv --python=python2.7 hotdoc_env
. hotdoc_env/bin/activate
pip install -r requirements.txt
```

### Actual build

```
mkdir build
cd build
meson ..
ninja-build || ninja
hotdoc run --conf-file ../hotdoc.json
```

### Rebuilding from scratch

```
touch ../hotdoc.json && hotdoc run --conf-file ../hotdoc.json
```

### Rebuilding with lots of logs

```
touch ../hotdoc.json && hotdoc run --conf-file ../hotdoc.json -vv
```

### Licensing

test_hotdoc is licensed under the DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE , see `COPYING` for more details.
