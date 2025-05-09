import React, { useState, useEffect } from 'react';
import { ListGroup, Spinner, Card, Modal, Button } from 'react-bootstrap';
import { ACCESS_TOKEN } from "../constants";
import api from '../api';

const GameBoardModal = ({ showBoard, handleCloseBoard }) => {
  const [matches, setMatches] = useState([]); // Estado para almacenar los partidos
  const [loading, setLoading] = useState(true); // Estado para manejar el estado de carga
  const [error, setError] = useState(''); // Estado para manejar posibles errores

  useEffect(() => {
    const fetchMatches = async () => {
      try {
        // Realiza la solicitud GET para obtener los partidos desde la API
        const response = await api.get('/api/matches/available/', {
          headers: {
            Authorization: `Bearer ${localStorage.getItem(ACCESS_TOKEN)}`,
          },
        });

        setMatches(response.data); // Asigna los partidos obtenidos a la variable de estado
      } catch (error) {
        setError('Failed to fetch matches'); // Si ocurre un error, actualiza el estado de error
      } finally {
        setLoading(false); // Deja de cargar después de obtener los datos
      }
    };

    fetchMatches(); // Llama a la función para obtener los partidos
  }, []); // El array vacío asegura que la llamada se haga solo una vez al montar el componente

  if (loading) {
    return (
      <Modal show={showBoard} onHide={handleCloseBoard}>
        <Modal.Header closeButton>
          <Modal.Title>Loading Matches...</Modal.Title>
        </Modal.Header>
        <Modal.Body className="text-center">
          <Spinner animation="border" />
          <p>Loading matches...</p>
        </Modal.Body>
      </Modal>
    );
  }

  if (error) {
    return (
      <Modal show={showBoard} onHide={handleCloseBoard}>
        <Modal.Header closeButton>
          <Modal.Title>Error</Modal.Title>
        </Modal.Header>
        <Modal.Body className="text-center text-danger">
          {error}
        </Modal.Body>
      </Modal>
    );
  }

  return (
    <Modal show={showBoard} onHide={handleCloseBoard} dialogClassName="custom-modal">
      <Modal.Header closeButton className="modal-header text-center">
        <Modal.Title>Join Game to Play!</Modal.Title>
      </Modal.Header>
      <Modal.Body className="modal-body">
        <ListGroup>
          {matches.length === 0 ? (
            <Card 
              body className="text-center text-white" 
              style={{"background-color":"#26292d", "border": "none"}}>
              No matches available.
            </Card>
          ) : (
            matches.map((match) => (
              <ListGroup.Item key={match.id} className="d-flex justify-content-between bg-dark text-white">
                <div>
                  <strong>{match.player_left_username}</strong> vs <strong>{match.player_right_username}</strong>
                </div>
                <Button variant="success">Join Game</Button>
              </ListGroup.Item>
            ))
          )}
        </ListGroup>
      </Modal.Body>
      <Modal.Footer style={{ border: 'none' }}>
        <Button variant="danger" onClick={handleCloseBoard}>Close</Button>
      </Modal.Footer>
    </Modal>
  );
};

export default GameBoardModal;


