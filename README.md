This is a test project for [hotdoc](https://github.com/hotdoc/hotdoc)

This project uses the gobject-introspection extension, and is configured
to use a gir file at build/Test-1.0.gir.

You can either build it yourself:

```
$ mkdir build
$ cd build
$ meson ..
$ ninja
```

or copy over the default gir:

```
mkdir build
cp Test-1.0.gir build
cd build
```

You can now run hotdoc with:

```
hotdoc run --conf-file ../hotdoc.json
```

### Licensing

test_hotdoc is licensed under the DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE , see `COPYING` for more details.
