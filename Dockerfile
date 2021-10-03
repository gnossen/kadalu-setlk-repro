FROM phusion/baseimage:master

WORKDIR /

RUN apt-get update -y && \
    apt-get install -y build-essential

COPY main.c Makefile /

RUN make repro

FROM phusion/baseimage:master

COPY --from=0 /repro /repro

RUN mkdir -p /mnt/data

CMD ["/repro", "/mnt/data/test.db"]
