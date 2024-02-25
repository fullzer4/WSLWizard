type TGraphProps = {
    label: string,
}

const Graph = (props: TGraphProps) => {
    return(
        <div>
            <p>{props.label}</p>
        </div>
    )
}

export default Graph