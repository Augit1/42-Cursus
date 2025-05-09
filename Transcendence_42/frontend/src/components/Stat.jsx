import { Row } from 'react-bootstrap';
import '../styles/profile.css'

export default function Stat({title, value}) {
    return (
			<Row className="justify-content-md-center">
				<div className='stat-wrapper'>
						<h3>{title}</h3>
					<div className='stat'>
						<h3>{value}</h3>
					</div>
				</div>
			</Row>
    );
}