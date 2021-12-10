folder("Tools")
{
    displayName("Tools")
    description("Folder for miscellaneous tools.")
}

job("Tools/clone-repository")
{
    parameters
    {
        stringParam("GIT_REPOSITORY_URL", "", "Git URL of the repository to clone")
        // stringParam(ID, DEFAULT_VALUE, DESC)
    }

    steps
    {
        shell("git clone $GIT_REPOSITORY_URL")
    }

    wrappers
    {
        preBuildCleanup()
        // Clean workspace
    }
}

job("Tools/SEED")
{
    parameters
    {
        stringParam("DISPLAY_NAME", "", "Display name for the job")
        stringParam("GITHUB_NAME", "", "GitHub repository owner/repo_name (e.g.: \"EpitechIT31000/chocolatine\")") 
        // stringParam(ID, DEFAULT_VALUE, DESC)
    }

    steps
    {
        dsl
        {
            text("""pipelineJob("Tools/$DISPLAY_NAME")
{
    wrappers
    {
        preBuildCleanup()
    }

    scm
    {
        github("$GITHUB_NAME")
    }

    triggers
    {
        scm("1 * * * *")
    }
    
    steps
    {
        shell("make fclean")
        shell("make")
        shell("make test")
        shell("make clean")
    }
}
            """)
        }
    }
}
