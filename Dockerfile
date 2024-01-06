FROM ubuntu:20.04

WORKDIR /compileCodebook

COPY . .

ARG DEBIAN_FRONTEND=noninteractive

RUN apt-get update && \
    apt-get install -y texlive-xetex fonts-noto-cjk &&\
    apt-get install -y fonts-ubuntu fontconfig


CMD ["xelatex", "codebook.tex"]
