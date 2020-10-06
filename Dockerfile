FROM codenvy/cpp_gcc 
COPY ./* /app/
WORKDIR /app/
RUN g++ main.cpp -o program
WORKDIR /app/output
