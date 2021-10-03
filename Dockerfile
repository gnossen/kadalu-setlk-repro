FROM alpine:3.13.6

WORKDIR /

RUN apk add gcc make musl-dev

COPY main.c Makefile /

RUN make repro

FROM alpine:3.13.6

COPY --from=0 /repro /repro

RUN mkdir -p /mnt/data

CMD ["/repro", "/mnt/data/test.db"]
