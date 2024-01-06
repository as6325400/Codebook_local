IMAGE_NAME="codebook"

if ! docker images "$IMAGE_NAME" | grep -q "$IMAGE_NAME"; then
    echo "Building xeLatex Docker image..."
    sudo docker build -t "$IMAGE_NAME" .
else
    echo "Docker image $IMAGE_NAME already exists."
fi

echo "Running Docker container..."
sudo docker run --name codebookLatex "codebook"

echo "Copying PDF from container to host..."
sudo docker cp codebookLatex:/compileCodebook/codebook.pdf .

echo "Stopping and removing container..."
sudo docker stop codebookLatex
sudo docker rm codebookLatex

echo "Done."