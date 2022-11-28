memalloc
===

This is a simple memory allocator for C where malloc(), calloc(), realloc() and free() are reimplemented.

* Basic file opening, viewing and editing
* Saving to disk with confirmation messages
* Basic filetype detection and syntax highlighting
* Simple search functionalities
* Builtin keybinds

Running
-------

```
gcc -o memalloc.so -fPIC -shared memalloc.c
```

The `-fPIC` and `-shared` options makes sure the compiled output has position-independent code and tells the linker to produce a shared object suitable for dynamic linking.

On Linux, if you set the enivornment variable `LD_PRELOAD` to the path of a shared object, that file will be loaded before any other library. We could use this trick to load our compiled library file first, so that the later commands run in the shell will use our malloc(), free(), calloc() and realloc().

```
export LD_PRELOAD=$PWD/memalloc.so
```

Now, if you run something like `ls`, it will use our memory allocator.
```
ls
memalloc.c		memalloc.so		README.md
```
or
```
vim memalloc.c
```

You can also run your own programs with this memory allocator.

Once you're done experimenting, you can do `unset LD_PRELOAD` to stop using our allocator.

[1]: https://rustup.rs/