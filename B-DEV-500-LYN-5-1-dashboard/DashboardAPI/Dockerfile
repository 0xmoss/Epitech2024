# setting up docker environnement

FROM mcr.microsoft.com/dotnet/sdk:5.0 AS build-env
WORKDIR /api
COPY . /api

RUN dotnet restore

# build project
RUN dotnet build

RUN dotnet dev-certs https --clean
RUN dotnet dev-certs https --trust

# expose port
EXPOSE 8081
