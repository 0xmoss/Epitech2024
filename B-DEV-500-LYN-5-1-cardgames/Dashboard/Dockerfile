# setting up docker environnement

FROM mcr.microsoft.com/dotnet/sdk:5.0 AS build-env
WORKDIR /app
COPY . /app

RUN dotnet restore

# install mongodb
RUN ["dotnet", "add", "package", "MongoDB.Driver"]

# install Spotify wrapper
RUN ["dotnet", "add", "package", "SpotifyAPI.Web"]
RUN ["dotnet", "add", "package", "SpotifyAPI.Web.Auth"]
RUN ["dotnet", "add", "package", "SpotifyApi.NetCore"]

# install restsharp
RUN ["dotnet", "add", "package", "RestSharp"]

# build project
RUN ["dotnet", "build"]

# expose port
EXPOSE 8080

#RUN ["./bin/Debug/net5.0/Dashboard"]