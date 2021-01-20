FROM alpine:latest

RUN apk update && \
    apk upgrade && \
    apk add --no-cache build-base

ENV CC=gcc
ENV CXX=g++

WORKDIR /lab

ENTRYPOINT [ "sh", "-c" ]
