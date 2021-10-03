10/3/2021

So this bug has been plaguing me for a while now. I'm pretty sure that it is
solely a gluster bug at this point. This repo houses an incredibly simple repro.
I've tested it against both glibc and musl libc and it reproduces. As of right
now though, I can only reproduce via my k8s cluster. The next step is to
reproduce locally. Once I can do that, I can figure out the exact location where
there is an issue and _maybe_ create a patch to fix it.

Okay. I think I just build gluster locally and can run it.
