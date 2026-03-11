FROM ubuntu:24.04
ENV DEBIAN_FRONTEND=noninteractive


#https://askubuntu.com/questions/355565/how-do-i-install-the-latest-version-of-cmake-from-the-command-line
RUN apt update
RUN apt install -y curl
RUN apt install -y libssl-dev
RUN apt install -y build-essential
RUN apt install -y libtool
RUN apt install -y autoconf
RUN apt install -y unzip
RUN apt install -y wget
RUN apt install -y git

# Install CMake 4.x from official source (apt only provides 3.28 on Ubuntu 24.04)
RUN wget https://github.com/Kitware/CMake/releases/download/v4.0.1/cmake-4.0.1-linux-x86_64.sh \
    -O /tmp/cmake-install.sh && \
    chmod +x /tmp/cmake-install.sh && \
    /tmp/cmake-install.sh --skip-license --prefix=/usr/local && \
    rm /tmp/cmake-install.sh

RUN echo "cmake installed version: $(cmake --version)"
RUN echo "installing Quests ..."
WORKDIR /usr/local
RUN git clone https://github.com/Dandjix/SpaceshipQuests SpaceshipQuests
WORKDIR /usr/local/SpaceshipQuests
RUN chmod u+x ./install.sh
RUN ./install.sh

RUN echo "installing MongoDB Client ..."
WORKDIR /usr/local/MongoDB
COPY install_mongo_db.sh ./install.sh
RUN chmod u+x ./install.sh
RUN ./install.sh

RUN echo "installing Server ..."
WORKDIR /usr/local/QuestsServer
COPY imported ./imported
COPY src ./src
COPY CMakeLists.txt ./CMakeLists.txt

RUN mkdir build

WORKDIR /usr/local/QuestsServer/build
RUN cmake .. -DCMAKE_PREFIX_PATH=~/.local
RUN make

EXPOSE 8080

CMD ["sh", "-c", "./QuestsServer 0.0.0.0 8080"]