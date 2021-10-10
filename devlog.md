10/3/2021

So this bug has been plaguing me for a while now. I'm pretty sure that it is
solely a gluster bug at this point. This repo houses an incredibly simple repro.
I've tested it against both glibc and musl libc and it reproduces. As of right
now though, I can only reproduce via my k8s cluster. The next step is to
reproduce locally. Once I can do that, I can figure out the exact location where
there is an issue and _maybe_ create a patch to fix it.

Okay. I think I just build gluster locally and can run it.

And... I can't reproduce it locally. Wonderful. I just used a single,
non-replicated volume this type. I guess the next step is to try the specific
tag that is being used by kadalu.

And now I've verified that I can't reproduce this from the commit immediately
before May 20th. What's worse is that I can't find a release version from the
date that this gluster build is purportedly from. This is starting to look like
an issue either with Kadalu's vendored gluster or its configuration of it.

Debugging this is going to get tricky.

Well look at this. This issue seems to describe my problem exactly:
https://github.com/kadalu/kadalu/issues/287

Unfortunately, following its advice has _not_ fixed the issue.
