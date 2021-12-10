# setting up docker environnement

FROM mcr.microsoft.com/dotnet/sdk:5.0 AS build-env
WORKDIR /api
COPY . /api

RUN dotnet restore

# install mongodb
RUN ["dotnet", "add", "package", "MongoDB.Driver"]

# build project
RUN ["dotnet", "build"]

# expose port
EXPOSE 8081

#RUN ["./bin/Debug/net5.0/Dashboard"]