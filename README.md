# ab-audio

ab-audio is a tool to quickly switch between audio files to compare their quality.

## How to compile

```
$ apt-get install libpulse-dev
$ make
```

## How to run

```
$ ./build/ab a.wav b.wav
```

## Tutorial

Switch to a.wav:

```
> s 0
```

Switch to b.wav:

```
> s 1
```

Seek forward:

```
> l
```

Seek backward:

```
> h
```

Quit:

```
> q
```
